#include <openssl/aes.h>

int main() {
  // Generate a random encryption key.
  unsigned char key[AES_BLOCK_SIZE];
  RAND_bytes(key, AES_BLOCK_SIZE);

  // Open the file to be encrypted.
  FILE *infile = fopen("input.txt", "rb");
  if (infile == NULL) {
    printf("Error opening input file.\n");
    return 1;
  }

  // Create an AES context.
  AES_KEY aes_key;
  AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &aes_key);

  // Open the file to be written to.
  FILE *outfile = fopen("output.txt", "wb");
  if (outfile == NULL) {
    printf("Error opening output file.\n");
    fclose(infile);
    return 1;
  }

  // Encrypt the file.
  unsigned char buffer[AES_BLOCK_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, AES_BLOCK_SIZE, infile)) > 0) {
    AES_encrypt(buffer, buffer, &aes_key);
    fwrite(buffer, 1, bytes_read, outfile);
  }

  // Close the files.
  fclose(infile);
  fclose(outfile);

  return 0;
}
