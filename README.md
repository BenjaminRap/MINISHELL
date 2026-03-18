# MINISHELL

**Minishell** est une implémentation d'un shell Unix interactif inspiré de Bash, codé en C.
Il reproduit une partie significative du comportement d'un shell classique.

![demo](https://github.com/user-attachments/assets/4f100bf5-4485-4c01-9d3f-c37baa0bcb5c)

---

## Installation

<details>
<summary>🐳 Option 1 : Docker (toutes plateformes)</summary>

1. Installer Docker : [https://docs.docker.com/get-docker/](https://docs.docker.com/get-docker/)

2. Lancer le shell dans un conteneur Docker :

```bash
docker run --rm -it benjaminrap/minishell:latest
```

</details>

<details>
<summary>💻 Option 2 : Linux (Debian/Ubuntu)</summary>

1. Cloner le dépôt :

```bash
git clone https://github.com/BenjaminRap/MINISHELL.git
cd MINISHELL
```

2. Installer les dépendances :

```bash
sudo apt update
sudo apt install -y make gcc libreadline-dev
```

3. Compiler le projet :

```bash
make all
```

4. Lancer le shell :

```bash
./minishell
```

</details>

---

## Capacités

<details>
<summary>💾 Exécution de commandes</summary>
<br>
Le shell peut exécuter des programmes en les recherchant automatiquement dans la variable d'environnement `PATH`.

```bash
$ ls
minishell  README.md  src
```

</details>

<details>
<summary>🔗 Pipes</summary>
<br>
Les pipes permettent de connecter la sortie d'une commande à l'entrée d'une autre.

```bash
$ ls | wc -l
3
```

</details>

<details>
<summary>➡️ Redirections</summary>
<br>
Le shell supporte les redirections d'entrée et de sortie.

```bash
$ echo "hello world" > file.txt
$ cat file.txt
hello world
```

Redirection d'entrée :

```bash
$ wc -l < file.txt
1
```

Ajout à la fin d'un fichier :

```bash
$ echo "another line" >> file.txt
```

</details>

<details>
<summary>📄 Heredoc</summary>
<br>
Permet de fournir un bloc de texte directement à une commande.

```bash
$ cat << EOF
hello
world
EOF
hello
world
```

</details>

<details>
<summary>⚙️ Builtins</summary>
<br>
Certaines commandes sont exécutées directement par le shell :

* `cd`
* `echo`
* `pwd`
* `export`
* `unset`
* `env`
* `exit`

Exemple :

```bash
$ cd ..
$ pwd
/home/user
```

</details>

<details>
<summary>🌐 Variables d'environnement</summary>
<br>
Le shell permet d'utiliser et de définir des variables d'environnement.

```bash
$ export NAME=world
$ echo hello $NAME
hello world
```

Le code de retour de la dernière commande est accessible via `$?`.

```bash
$ ls
$ echo $?
0
```

</details>

<details>
<summary>⚡ Exécution conditionnelle</summary>
<br>
Le shell supporte les opérateurs logiques `&&` et `||`.

```bash
$ mkdir test && cd test
```

```bash
$ cat file.txt || echo "file not found"
file not found
```

</details>

<details>
<summary>🌀 Subshells</summary>
<br>
Les commandes peuvent être exécutées dans un sous-shell.

```bash
$ (cd /tmp && ls)
```

</details>

<details>
<summary>↔️ Navigation dans la ligne de commande</summary>
<br>
Grâce à l'intégration de `readline`, il est possible d'éditer la ligne de commande :

* déplacer le curseur avec les flèches gauche/droite
* modifier une commande avant de l'exécuter

</details>

<details>
<summary>📜 Historique des commandes</summary>
<br>
Les commandes précédemment exécutées sont sauvegardées dans l'historique.  
Les flèches haut et bas permettent de naviguer entre les commandes.

</details>

<details>
<summary>🔧 Autocomplétion</summary>
<br>
Le shell supporte l'autocomplétion des noms de fichiers et de dossiers.

```bash
$ Mak<TAB>
Makefile
```

</details>

<details>
<summary>🚨 Gestion des signaux</summary>
<br>
Le shell gère certains signaux utilisateur :

* `Ctrl + C` : signal `SIGINT`, interrompt la commande en cours ou crée une nouvelle ligne de shell
* `Ctrl + D` : envoie l'EOF, quitte le shell ou termine la saisie de l'entrée d'une commande
* `Ctrl + \` : signal `SIGQUIT`, interrompt la commande en cours

</details>

<details>
<summary>🌟 Wildcards</summary>
<br>
Le shell supporte l'expansion des wildcards.

```bash
$ ls *.c
main.c  parser.c  exec.c
```

</details>
