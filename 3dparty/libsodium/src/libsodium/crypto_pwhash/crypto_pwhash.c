
#include "crypto_pwhash.h"

size_t
crypto_pwhash_saltbytes(void)
{
    return crypto_pwhash_SALTBYTES;
}

size_t
crypto_pwhash_strbytes(void)
{
    return crypto_pwhash_STRBYTES;
}

const char *
crypto_pwhash_strprefix(void)
{
    return crypto_pwhash_STRPREFIX;
}

size_t
crypto_pwhash_opslimit_interactive(void)
{
    return crypto_pwhash_OPSLIMIT_INTERACTIVE;
}

size_t
crypto_pwhash_memlimit_interactive(void)
{
    return crypto_pwhash_MEMLIMIT_INTERACTIVE;
}

size_t
crypto_pwhash_opslimit_moderate(void)
{
    return crypto_pwhash_OPSLIMIT_MODERATE;
}

size_t
crypto_pwhash_memlimit_moderate(void)
{
    return crypto_pwhash_MEMLIMIT_MODERATE;
}

size_t
crypto_pwhash_opslimit_sensitive(void)
{
    return crypto_pwhash_OPSLIMIT_SENSITIVE;
}

size_t
crypto_pwhash_memlimit_sensitive(void)
{
    return crypto_pwhash_MEMLIMIT_SENSITIVE;
}

int
crypto_pwhash(unsigned char * const out, unsigned long long outlen,
              const char * const passwd, unsigned long long passwdlen,
              const unsigned char * const salt,
              unsigned long long opslimit, size_t memlimit)
{
    return crypto_pwhash_argon2i(out, outlen, passwd, passwdlen, salt,
                                 opslimit, memlimit);
}

int
crypto_pwhash_str(char out[crypto_pwhash_STRBYTES],
                  const char * const passwd, unsigned long long passwdlen,
                  unsigned long long opslimit, size_t memlimit)
{
    return crypto_pwhash_argon2i_str(out, passwd, passwdlen,
                                     opslimit, memlimit);
}

int
crypto_pwhash_str_verify(const char str[crypto_pwhash_STRBYTES],
                         const char * const passwd,
                         unsigned long long passwdlen)
{
    return crypto_pwhash_argon2i_str_verify(str, passwd, passwdlen);
}
