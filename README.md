# VaporCrack
![VaporCrack Logo](/assets/images/VaporCrack.png)

## Hash Cracker

### Supported algorithms
| Algorithm | Comand | 
| --- | --- |
| MD4 | `md4` |
| HALF-MD5 | `halfmd5` |
| MD5 | `md5` |
| SHA1 | `sha1` |
| SHA256 | `sha256` |
| SHA512 | `sha512` |
| BLAKE2s-256 | `blake2s` |
| BLAKE2b-512 | `blake2b` |

### Supported modes
| Mode | Command | Description |
| --- | --- | --- |
| Dictionnary | `-d` `--dictionnary` | This mode crack the hash using given wordlists |
| Brute | `-b` `--brute` | This mode crack the hash by crafting all possible words |

### Compiling instructions
```bash
gcc VaporCrack.c -lcrypto -o VaporCrack
```
