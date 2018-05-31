# RSA Encrpytion and Decryption

RSA algorithm uses a public key and private ke to encrypt and to descrypt data. 

RSA was named after Ron Rivest, Adi Shamir, abd Leonard Adleman, who invented the algorithm.

## RSA Algorithm

1. Choose two very large random prime numbers p and q
2. Compute modulus n = pq
3. Compute totient = (p-1)(q-1)
4. Choose an integer e (public key) such that 1 < e < totient and GCD(e, totient) = 1 (greatest common denomintor)
5. Choose an integer d (private key) such that de = 1 + k (totient).
6. Encryption: c = m^e mod n where m is the data to be encrypted
7. Descryption: m = c^d mod n where c is the encrypted data

## Project Highlights

1. Demonstrate key generation, encryption and descryption of RSA algorithm
2. Main program implemented in C programming language
3. A web page as the UI to take user inputs and go through the full algorithm
4. The UI will have three text boxes for user to enter: p, q, and a plain text message
5. A button to generate the private key and the public key
6. A button to encrypt the message and then to decrypt the message



 
