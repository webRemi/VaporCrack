# VaporCrack
![VaporCrack Logo](/assets/images/VaporCrack.png)

## Hash Cracker

### Supported modes
| Mode | Command | Description |
| --- | --- | --- |
| Help | `-h` `--help` | This mode display the help menu |
| Dictionnary | `-d` `--dictionnary` | This mode crack the hash using given wordlists |
| Brute | `-b` `--brute` | This mode crack the hash by crafting all possible words |

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
| RIPEMD-160 | `ripemd160` |

## Manual

### Compiling instructions
```bash
gcc VaporCrack.c -lcrypto -o VaporCrack
```

### Utilisation instructions
```bash
./VaporCrack -h
```
> Display help menu

```bash
./VaporCrack -d -a md5 <hash_file> <rockyou.txt>
```

> Crack the given hash using md5 algorithm, dictionnary mode and rockyou wordlist

```bash
./VaporCrack -b -a blake2s <hash_file>
```
> Crack the given hash using blake2s-256 algorithm and brute mode
