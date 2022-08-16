from pydoc import plain
from cryptography.fernet import Fernet #Encriptar
from datetime import datetime
import decimal
import time
import sys
import os
import math
import hmac
import base64
import pyotp #DELETE OR COMMENT

class bcolors:
    OK = "\033[92m"
    WARNING = "\033[93m"
    FAIL = "\033[91m"
    RESET = "\033[0m"

def create_key_fernet():
    key = Fernet.generate_key()  
    with open('.key.key', 'wb') as filekey: 
        filekey.write(key)
    print("Key fernet generate")

def get_key_fernet():
    with open('.key.key', 'rb') as filekey: 
        return(filekey.read())

def save_key(key):
    if os.path.exists(".key.key") == False:
        create_key_fernet()
    key_fernet = Fernet(get_key_fernet())
    encrypted = key_fernet.encrypt(key)
    with open("ft_otp.key", 'wb') as filekey: 
        filekey.write(encrypted)
    print(bcolors.OK + "Key was successfully saved in ft_otp.key" + bcolors.RESET)

def read_file(file):
    try:
        with open(key_file, 'rb') as filekey: 
            key = filekey.read()
            return(key)
    except:
        print(bcolors.FAIL + "Error: file key cant be open" + bcolors.RESET)
        exit()

def check_key(key):
    # try:
    #     with open(key_file, 'rb') as filekey: 
    #         key = filekey.read()
    # except:
    #     print(bcolors.FAIL + "Error: file key cant be open" + bcolors.RESET)
    #     exit()
    #key = read_file(key_file)
    try:
        ver = int(key, 16)
    except:
        print(bcolors.FAIL + "Error: key is not hexadecimal" + bcolors.RESET)
    if len(key) < 64:
        print(bcolors.FAIL + "Error: key must be 64 hexadecimal characters" + bcolors.RESET)
        exit()
    save_key(key)

def print_numbers(key):

    #print(key)
    key_fernet = Fernet(get_key_fernet())
    decrypted = key_fernet.decrypt(key)
    #print(decrypted)
    plain_text = decrypted.decode()
    #print(plain_text)
    changebase = base64.b32encode(decrypted)
    #print("BASE32         ", changebase)

    totp = pyotp.TOTP("")
    print("PYOTP NOW    ", totp.now())

    #print("BASE42         ", base64.b32encode(int(plain_text, 32)))
    now = int(time.time())
    #print("Unix time      ",now)
    #print("Unix time / 30 ", now/30)
    last = round(now/30, 0)
    #print(last)
    number = math.floor(last)
    #print("Floor          ", number)
    mensaje = bytes(str(number), 'utf-8')
    #mensaje = bytes(str(0), 'utf-8')
    #hmac.new(decrypted, mensaje, "sha1")
    hmac.new(b'', mensaje, "sha1")
    #print("HMAC           ", hmac)
    digest = hmac.digest(decrypted, mensaje, "sha1")
    #print("DIGEST         ",digest)
    #print("TEST            ", digest[len(digest) - 4:])
    test = base64.b16encode(digest[len(digest) - 4:])
    plain_text = test.decode()
    #print("TEST         ", test)
    #print("PLAIN TEXT   ", plain_text)
    inter = int(plain_text, 16)
    #print("INT         ", str(inter))
    module = inter % (10**6)
    # while len(str(module)) < 0:
    #     module = 0 + module
    print("MODULO       ", module)
    #print(type(module))


    hotp = pyotp.HOTP(changebase)
    print(hotp.at(0))
    print(hotp.at(number))
    #print(hotp.at(1401))

    # verifying HOTP codes with PyOTP
    #print(hotp.verify("316439", 1401))
    #print(hotp.verify("316439", 1402))
    
    totp = pyotp.TOTP('')
    print("Current OTP:", totp.now())
    if totp.verify(module) == True:
        print(bcolors.OK + "AVEMUS PROYECTO" + bcolors.RESET)

    new_current_time = 51610762
    print("NEW CURRENT TIME             ", new_current_time)
    new_current_time = bytes(str(new_current_time), 'utf-8')
    secret_key = ">cHSB_UQ#O5m;~b"
    print("SECRET KEY                   ", secret_key)
    secret_key = bytes(str(secret_key), 'utf-8')
    hmac.new(secret_key, new_current_time, "sha1")
    digest = hmac.digest(decrypted, mensaje, "sha1")
    print("DIGEST         ", str(digest))
    test = base64.b16encode(digest)
    print(test)




    # print("LEN            ", len(digest))
    # print("BASE16         ", base64.b16encode(digest))
    #print("BASE32         ", base64.b32encode(digest))
    # print("BASE64         ", base64.b64encode(digest))
    #print(int(digest, 16))

    # hashed = hmac.new(decrypted, mensaje, "sha1")
    
    # # The signature
    # digest_good = str(hashed.digest())
    # encode = digest_good.encode("base64")
    # print(encode)



if __name__ == '__main__':
    opts = [opt for opt in sys.argv[1:]]
    if "-g" in opts:
        try:
            key_file = opts[opts.index("-g") + 1]
        except:
            print(bcolors.FAIL + "Error: invalid name for key file" + bcolors.RESET)
            exit()
        check_key(read_file(key_file))
    elif "-k" in opts:
        try:
            key_file = opts[opts.index("-k") + 1]
        except:
            print(bcolors.FAIL + "Error: invalid name for key file" + bcolors.RESET)
            exit()
        print_numbers(read_file(key_file))
    date = datetime.now()
    #print(date)

