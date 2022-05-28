#!/usr/bin/env python
import uuid

# Tham khảo:
# - https://stackoverflow.com/a/159195
# - https://www.geeksforgeeks.org/extracting-mac-address-using-python/

def get_mac_address_1():
    int_mac = uuid.getnode()
    hex_mac_fmt = ':'.join(['{:02x}'.format((int_mac >> x) & 0xff)
                           for x in range(0, 8*6, 8)][::-1])
    return hex_mac_fmt


# Tham khảo:
# - https://stackoverflow.com/a/3499533

def get_mac_address_2():
    int_mac = uuid.getnode()
    hex_mac = hex(int_mac)[2:] # Remove '0x'
    if len(hex_mac) < 12:
        hex_mac = '0' * (12 - len(hex_mac)) + hex_mac
    blocks = [hex_mac[x:x+2] for x in range(0, len(hex_mac), 2)]
    hex_mac_fmt = ':'.join(blocks)
    return hex_mac_fmt


if __name__ == '__main__':
    print(get_mac_address_1())
    print(get_mac_address_2())
