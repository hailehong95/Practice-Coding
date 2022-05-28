#!/usr/bin/env python
import socket


# Ref: https://stackoverflow.com/a/28950776
def get_primary_ip_without_internet(host='10.255.255.255', port=1):
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        sk.connect((host, port))
        primary_ip = sk.getsockname()[0]
    except Exception:
        primary_ip = '127.0.0.1'
    finally:
        sk.close()
    return primary_ip


# Ref: https://stackoverflow.com/a/28950776
def get_primary_ip_with_internet(host='www.google.com', port=80, timeout=5):
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        sk.settimeout(timeout)
        sk.connect((socket.gethostbyname(host), port))
        primary_ip = sk.getsockname()[0]
    except:
        primary_ip = '127.0.0.1'
    finally:
        sk.close()
    return primary_ip


if __name__ == '__main__':
    print(get_primary_ip_without_internet())
    print(get_primary_ip_with_internet())
