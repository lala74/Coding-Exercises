# Drinking Song <!-- omit in toc -->

[Link](https://open.kattis.com/problems/drinkingsong)

## Problem
Ninety-Nine Bottles of Beer is an anonymous folk song dating to the mid-20th century. It is a traditional reverse counting song, sometimes used to sing on long trips, as it has a very repetitive format which is easy to memorize and can take a long time to sing. The lyrics describe a quantity of bottles that is reduced by 1 in every verse, until no bottles are left, at which point the song ends somewhat abruptly.

Many variations and similar songs are known in other languages.

**Input**  
The input consists of exactly two lines. On the first line, the number N of bottles 1≤N≤99. On the second line, a single word of at most 20 lower- or uppercase characters from the English alphabet, not using whitespace, describing a beverage.

```
3
milk
```

**Output**  
The full lyrics of the song, starting with N, and counting down until the last bottle gets taken. The lyrics are given by example below. Note the grammatical changes in the last two verses.

```
3 bottles of milk on the wall, 3 bottles of milk.
Take one down, pass it around, 2 bottles of milk on the wall.

2 bottles of milk on the wall, 2 bottles of milk.
Take one down, pass it around, 1 bottle of milk on the wall.

1 bottle of milk on the wall, 1 bottle of milk.
Take it down, pass it around, no more bottles of milk.

```
