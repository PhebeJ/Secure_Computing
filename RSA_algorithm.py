def RSA_Algorithm(p:int, q:int, m:int):
    n=p*q
    phi=(p-1)*(q-1)
    e=find_e(phi)
    d=find_d(e,phi)
    C=(m**e)%n
    P=(C**d)%n
    print("p=",p, '       q =',q,'  n =',n, 'Plain Text =', m)
    print("Encryption Key,e = ",e)
    print('Decryption key,d = ',d)
    print('Cipher Text = ',C)
    print('Plaintext after decryption =',P)
    return C,P

def find_e(phi:int):
    e=2
    while e<phi :
        if gcd(e,phi) == 1:
            return e
        e=e+1

def find_d(e:int,phi:int):
    d=2
    while d<phi :
        if ((d*e)%phi)==1:
            return d
        d = d+1

def gcd(x:int, y:int):
    small,large=(x,y) if x<y else (y,x)
    while small != 0:
        temp = large % small
        large = small
        small =temp
    return large

if __name__ == '__main__':
    print('RSA Encryption and Decryption')
print('Enter p, q and message,m---------->')
p=int(input('p='))
q=int(input('q='))
m=int(input('m='))
RSA_Algorithm(p,q,m)