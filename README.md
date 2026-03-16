# MINISHELL

<span style="font-size: 18px">**Minishell** est une implémentation d'un shell Unix interactif inspiré de Bash, codé en C.
Il reproduit une partie significative du comportement d'un shell classique.</span>

---

## Installation

<details>
<summary style="font-size: 18px">Option 1 : Docker (toutes plateformes)</summary>

1. Installer Docker : [https://docs.docker.com/get-docker/](https://docs.docker.com/get-docker/)

2. Lancer le shell dans un conteneur Docker :

```bash
docker run --rm -it benjaminrap/minishell:latest
````

</details>

<details>
<summary style="font-size: 18px">Option 2 : Linux (Debian/Ubuntu)</summary>

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

<div style="padding-left: 10px">
<details>
<summary style="font-size: 18px; ">Exécution de commandes</summary>


  Le shell peut exécuter des programmes en les recherchant automatiquement dans la variable d'environnement `PATH`.

```bash
$ ls
minishell  README.md  src
````
</details>

<details>
<summary style="font-size: 18px">Pipes</summary>

Les pipes permettent de connecter la sortie d'une commande à l'entrée d'une autre.

```bash
$ ls | wc -l
3
```
</details>

<details>
<summary style="font-size: 18px">Redirections</summary>

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
<summary style="font-size: 18px">Heredoc</summary>

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
<summary style="font-size: 18px">Builtins</summary>

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
<summary style="font-size: 18px">variables d'environnement</summary>

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
<summary style="font-size: 18px">Exécution conditionnelle</summary>

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
<summary style="font-size: 18px">Séparation de commandes</summary>

Plusieurs commandes peuvent être exécutées sur une seule ligne avec `;`.

```bash
$ echo hello ; echo world
hello
world
```
</details>

<details>
<summary style="font-size: 18px">Subshells</summary>

Les commandes peuvent être exécutées dans un sous-shell.

```bash
$ (cd /tmp && ls)
```
</details>

<details>
<summary style="font-size: 18px">Navigation dans la ligne de commande</summary>

Grâce à l'intégration de `readline`, il est possible d'éditer la ligne de commande :

* déplacer le curseur avec les flèches gauche/droite
* modifier une commande avant de l'exécuter
</details>

<details>
<summary style="font-size: 18px">Historique des commandes</summary>

Les commandes précédemment exécutées sont sauvegardées dans l'historique.

```bash
$ history
1  ls
2  echo hello
3  cat file.txt
```
</details>

<details>
<summary style="font-size: 18px">Autocomplétion</summary>

Le shell supporte l'autocomplétion pour faciliter la saisie des commandes.

```bash
$ ec<TAB>
echo
```
</details>

<details>
<summary style="font-size: 18px">Gestion des signaux</summary>

Le shell gère certains signaux utilisateur :

* `Ctrl + C` : interrompt la commande en cours
* `Ctrl + D` : quitte le shell
* `Ctrl + \` : signal `SIGQUIT`
</details>

<details>
<summary style="font-size: 18px">Commentaires</summary>

Le shell supporte les commentaires dans les commandes.

```bash
$ echo hello # ceci est un commentaire
hello
```

Les commentaires peuvent également s'étendre sur plusieurs lignes.
</details>

<details>
<summary style="font-size: 18px">Wildcards</summary>

Le shell supporte l'expansion des wildcards.

```bash
$ ls *.c
main.c  parser.c  exec.c
```

```bash
$ ls file?.txt
file1.txt  file2.txt
```
</details>
</div>
