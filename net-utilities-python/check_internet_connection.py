#!/usr/bin/env python

import urllib
import socket
import requests


# Ref: https://stackoverflow.com/a/50558001
def internet_check_by_urllib(url='http://www.google.com/', timeout=5):
    try:
        _ = urllib.request.urlopen(url, timeout=timeout)
        return True
    except:
        pass
    return False


# Ref: https://stackoverflow.com/a/24460981
def internet_check_by_requests(url='http://www.google.com/', timeout=5):
    try:
        _ = requests.head(url, timeout=timeout)
        return True
    except requests.ConnectionError:
        pass
    return False


# Ref: https://stackoverflow.com/a/33117579
def internet_check_by_socket(host="8.8.8.8", port=53, timeout=5):
    try:
        socket.setdefaulttimeout(timeout)
        socket.socket(socket.AF_INET, socket.SOCK_STREAM).connect((host, port))
        return True
    except:
        pass
    return False


if __name__ == '__main__':
    print(internet_check_by_urllib())
    print(internet_check_by_requests())
    print(internet_check_by_socket())