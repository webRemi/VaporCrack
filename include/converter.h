#ifndef CONVERTER_H
#define CONVERTER_H

extern char *convert_to_md4(char *word); 
extern char *convert_to_halfmd5(char *word); 
extern char *convert_to_md5(char *word); 
extern char *convert_to_sha1(char *word); 
extern char *convert_to_sha256(char *word); 
extern char *convert_to_sha512(char *word); 
extern char *convert_to_blake2s(char *word); 
extern char *convert_to_blake2b(char *word); 
extern char *convert_to_ripemd160(char *word); 
extern char *convert_to_whirlpool(char *word); 
extern char *convert_to_sm3(char *word);
extern char *convert_to_ntlm(char *word);

#endif
