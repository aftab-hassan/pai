#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
//#include<paillier.h>
#include"paillier.h"
#include <string.h>
#include<malloc.h>

int main()
{
 int n=4; //degree of polynomial
 int i=0;
 //char* str;
 void* myvoid;
 int* myintp;
 //str = malloc(1000*sizeof(char));
 FILE* fp;

 fp = fopen("file.txt","a");

 paillier_pubkey_t *pub_key=(paillier_pubkey_t *)malloc(sizeof(paillier_pubkey_t));
 paillier_prvkey_t *prv_key=(paillier_prvkey_t *)malloc(sizeof(paillier_prvkey_t));
 paillier_keygen(4,&pub_key,&prv_key,paillier_get_rand_devrandom);

 for(i=0;i<n;i++)
 {  
  unsigned int p=rand()%20;
  paillier_plaintext_t *ptext = paillier_plaintext_from_ui(p);
  
  
  paillier_ciphertext_t *ctext;
  ctext = paillier_enc(0, pub_key, ptext, paillier_get_rand_devrandom);
  
  //str = (char*)paillier_ciphertext_to_bytes(n,ctext);
  myintp = (int*)paillier_ciphertext_to_bytes(n,ctext);
  myvoid = paillier_ciphertext_to_bytes(n,ctext);
  //printf("str==[%s]\n",str);
  printf("number==[%d]\n",*myintp);
  fwrite(myvoid, 1, PAILLIER_BITS_TO_BYTES(pub_key->bits)*2, fp);
  //printf("myvoid==[%s]\n",myvoid);
  //printf("number_str==[%d]\n",(int)strtol(str,NULL,16));
  //printf("number_myvoid==[%d]\n",(int)strtol(myvoid,NULL,16));
  //printf("number_charstarmyvoid==[%d]\n",(int)strtol((char*)myvoid,NULL,16));
 }

 fclose(fp);
  
 return 0;
}
