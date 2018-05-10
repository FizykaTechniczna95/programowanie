def prime_generator(_min):
    tmp=3
    while tmp>2:
        tmp=0
        for i in range(_min):
            if _min%(i+1)==0:
                tmp+=1
        _min += 1
    return _min-1

def modinv(x,y):
    r, s = 1,0
    while y:
        r,s = s, r- x//y *s
        x, y = y, x%y
    return r

def generate_keys():
    p  = prime_generator(123456)
    q = prime_generator(4567)
    n = p*q
    phi = n-p-q+1
    e = 65537
    d = modinv(e,phi)% phi
    return [e,n], [d, n]

def rsa(msg, key):
    return pow(msg, *key)

pub, priv = generate_keys()
crypto = rsa(12,pub)
msg = rsa(crypto, priv)
print("PUB\n{}\n\nPRIV:\n{}\n\nCRYPTO:\n{}\n\nMSG:\n{}\n".format(pub, priv, crypto, msg))
    
