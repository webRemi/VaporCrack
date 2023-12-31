# VaporCrack
![VaporCrack Logo](/assets/images/VaporCrack.png)

## Hash Cracker
* 1 analyze mode
* 3 cracking modes
* More than 10 hashes algorithms supported

### Supported modes
| Mode | Command | Description |
| --- | --- | --- |
| Help | `-h` `--help` | This mode display the help menu |
| Identify | `-i` `--identify` | This mode identify possible algorithm used by hash |
| Dictionary | `-d` `--dictionary` | This mode crack the hash using given wordlists |
| Brute | `-b` `--brute` | This mode crack the hash by crafting all possible words |
| Combinatory | `-c` `--combinatory` | This mode crack the hash by using combinated wordlists |

### Supported cooks
| Cook | Command | Description |
| --- | --- | --- |
| Lowercase | lower | Cook all possible lower case combinations |
| Uppercase | upper | Cook all possible upper case combinations |
| Number | number | Cook all possible number combinations |
| Special | special | Cook all possible special combinations |
| Full | full | Cook ALL possible combinations |

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
| WHIRLPOOL | `whirlpool` |
| SM3 | `sm3` |
| NTLM | `ntlm` | 
## Manual

### Compiling instructions
Navigate to the project directory and run:
```bash
make
```

### Installation instructions
Navigate to the project directory and run:
```bash
make install
```

### Utilisation instructions
```bash
VaporCrack -h
```
> Display help menu

```bash
VaporCrack -i <hash_file>
```
> Identify possible algorithms used by hash

```bash
VaporCrack -d -a md5 <hash_file> <rockyou.txt>
```
> Crack the given hash using md5 algorithm, dictionary mode and rockyou wordlist

```bash
VaporCrack -b -a blake2s <hash_file> full
```
> Crack the given hash using blake2s-256 algorithm, brute mode and full cook

> Example: P@ssw0rd!
```bash
VaporCrack -b -a sha1 <hash_file> number
```
> Crack the given hash using sha1 algorithm, brute mode and number cook

> Example: 15684

```bash
VaporCrack -c -a ntlm <hash_file> <rockyou.txt> <rockyou.txt>
```
> Crack the given hash using ntlm algorithm, combinator mode and two rockyou lists

> Example: iloveyousunshine!!

```bash
VaporCrack -c -a md4 <hash_file> <season.txt> <year.txt>
```
> Crack the given hash using md4 algorithm, combinator mode and two different lists

> Example: Summer2023
