# ft_printf

## Description
Le projet ft_printf de l'école 42 consiste à recoder la fonction printf() de la bibliothèque libc. La fonction ft_printf() doit imiter le comportement de printf() tout en offrant quelques fonctionnalités supplémentaires. La bibliothèque résultante, libftprintf.a, doit être créée à l'aide de la commande ar.

## Partie Obligatoire

### Sujet
- [x] **[Sujet](en.subject.pdf):** Voici le sujet de ft_printf().

### Fonction Principale

- [x] **[ft_printf.c](ft_printf.c):**
  - Fonction principale de la bibliothèque ft_printf. Elle implémente la logique principale pour interpréter le format fourni et appeler les fonctions appropriées pour chaque conversion.
  - La fonction ft_printf prend en charge les conversions suivantes : 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', et '%'.
  - Elle utilise les fichiers auxiliaires pour gérer les différentes conversions et afficher les résultats.
  - Les conversions sont effectuées en utilisant les spécifications de format de la chaîne de format fournie.

### Fichiers Associés

- [x] **[ft_parse_format.c](ft_parse_format.c):**
  - Fonction permettant de parser le format de la chaîne de format de ft_printf() pour extraire les indicateurs de conversion et leurs options associées.

- [x] **[ft_print_char.c](ft_print_char.c):**
  - Fonction de ft_printf() pour gérer la conversion du format '%c' et imprimer un seul caractère.

- [x] **[ft_print_str.c](ft_print_str.c):**
  - Fonction de ft_printf() pour gérer la conversion du format '%s' et imprimer une chaîne de caractères.

- [x] **[ft_print_d_i.c](ft_print_d_i.c):**
  - Fonction de ft_printf() pour gérer les conversions des formats '%d' et '%i' et imprimer des nombres entiers signés.

- [x] **[ft_print_u.c](ft_print_u.c):**
  - Fonction de ft_printf() pour gérer la conversion du format '%u' et imprimer un nombre entier non signé.

- [x] **[ft_print_x_X.c](ft_print_x_X.c):**
  - Fonction de ft_printf() pour gérer les conversions des formats '%x' et '%X' et imprimer des nombres entiers en notation hexadécimale.

- [x] **[ft_print_p.c](ft_print_p.c):**
  - Fonction de ft_printf() pour gérer la conversion du format '%p' et imprimer un pointeur.

- [x] **[ft_itoa_nosigne.c](ft_itoa_nosigne.c):**
  - Fonction auxiliaire pour ft_printf() qui convertit un entier en chaîne de caractères sans prendre en compte le signe.

- [x] **[ft_itoa_unsigned.c](ft_itoa_unsigned.c):**
  - Fonction auxiliaire pour ft_printf() qui convertit un entier non signé en chaîne de caractères.

- [x] **[ft_itoa_base_16.c](ft_itoa_base_16.c):**
  - Fonction auxiliaire pour ft_printf() qui convertit un entier en chaîne de caractères en base 16.

- [x] **[ft_itoa_p.c](ft_itoa_p.c):**
  - Fonction auxiliaire pour ft_printf() qui convertit un pointeur en chaîne de caractères en base 16.

- [x] **[ft_printf.h](ft_printf.h):**
  - Fichier d'en-tête contenant les prototypes des fonctions associées à ft_printf().

### Makefile
- [x] **[Makefile](Makefile):** Fichier de compilation avec les règles suivantes : NAME, all, clean, fclean, re.

## Conversion Supportées

- [x] %c : Imprime un caractère.
- [x] %s : Imprime une chaîne de caractères.
- [x] %p : Imprime un pointeur void* en format hexadécimal.
- [x] %d : Imprime un nombre décimal (base 10).
- [x] %i : Imprime un entier en base 10.
- [x] %u : Imprime un nombre décimal non signé (base 10).
- [x] %x : Imprime un nombre en hexadécimal (base 16) en minuscules.
- [x] %X : Imprime un nombre en hexadécimal (base 16) en majuscules.
- [x] %% : Imprime le caractère '%'.

## Partie Bonus

### Bonus Supportés
1. **Combinaison d'Indicateurs de Format : ’-0.’ et Largeur Minimale du Champ**
   - Gérer n'importe quelle combinaison des indicateurs de format : ’-', '0', '.' et spécifier une largeur minimale du champ pour toutes les conversions.
   - Explication :
      - `'-'` : Aligner à gauche. Le résultat est aligné sur le côté gauche de la largeur du champ.
      - `'0'` : Remplir avec des zéros. Si la largeur du champ est spécifiée, remplir les espaces vides avec des zéros au lieu d'espaces.
      - `'.'` : Précision. Pour les conversions numériques, cela spécifie le nombre de chiffres à imprimer après le point décimal.

2. **Indicateurs de Format : ’# +’**
   - Gérer tous les indicateurs de format suivants : ’# +’.
   - Explication :
      - `'#'` : Forme alternative. Pour les conversions numériques, ajouter un préfixe ('0x' ou '0X') aux valeurs non nulles.
      - `'+'` : Force l'affichage du signe. Imprime toujours un signe ('+' ou '-') devant les nombres. Par défaut, seulement les nombres négatifs sont préfixés avec un signe.


## Utilisation
### main.c
```c
#include "ft_printf.h"
#include <stdio.h>
#define TEST "[%#x]\n", 0

int	main(void)
{
	int	i;
	int	j;

	i = ft_printf(TEST);
	j = printf(TEST);
	printf("i = %d\nj = %d\n", i, j);
	return (0);
}
```
### Compilation
Utilisez le Makefile pour compiler le projet et créer la bibliothèque libftprintf.a. Exécutez la commande suivante dans le terminal :

```bash
make
```
Pour compiler le projet et avoir l'executable . Exécutez la commande suivante dans le terminal : 
```bash
make test
```

