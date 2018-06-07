# RSA Encrpytion and Decryption

RSA algorithm uses a public key and private key to encrypt and to descrypt data. 

RSA was named after Ron Rivest, Adi Shamir, abd Leonard Adleman, who invented the algorithm.

## RSA Algorithm

1. Choose two very large random prime numbers p and q
2. Compute modulus n = pq
3. Compute phi = (p-1)(q-1)
4. Choose an integer e (public key) such that 1 < e < phi and GCD(e, totient) = 1 (greatest common denomintor)
5. Choose an integer d (private key) such that d * e = 1 + k (phi).
6. Encryption: c = m^e mod n where m is the data to be encrypted
7. Descryption: m = c^d mod n where c is the encrypted data

## Project Highlights

1. Use C programming language to implement RSA algorithm.
2. The C code can take a random seed to encrypt a message and then decrypt it
3. Demonstrate key generation, encryption and descryption of RSA algorithm
4. Main program implemented in C programming language
5. A web page as the UI to take user inputs and go through the full algorithm
6. The UI will have two text boxes for user to enter: random seed and a plain text message

## Files

* rsa.c: full RSA algorithm implementation
* index.php: webpage with php to call rsa C program demo
* Makefile: to compile rsa C code
** To compile: make
** To clean: make clean
** To install, assuming sudo permission: make install		


 
