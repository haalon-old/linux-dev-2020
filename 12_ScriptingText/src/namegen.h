/* COMMENT:: namegen 0.0:Пт 11 дек 2020 16:05:40 MSK */
/** @file namegen.h
 * Fantasy name generator ANSI C header library
 *
 * This is free and unencumbered software released into the public domain.
 *
 * The `namegen()` function creates a name generator based on an input
 * pattern. The letters s, v, V, c, B, C, i, m, M, D, and d represent
 * different types of random replacements. Everything else is emitted
 * literally.
 *
 * - s - generic syllable
 * - v - vowel
 * - V - vowel or vowel combination
 * - c - consonant
 * - B - consonant or consonant combination suitable for beginning a word
 * - C - consonant or consonant combination suitable anywhere in a word
 * - i - insult
 * - m - mushy name
 * - M - mushy name ending
 * - D - consonant suited for a stupid person's name
 * - d - syllable suited for a stupid person's name (begins with a vowel)
 *
 * All characters between parenthesis () are emitted literally. For
 * example, the pattern "s(dim)", emits a random generic syllable
 * followed by "dim".
 *
 * Characters between angle brackets <> emit patterns from the table
 * above. Imagine the entire pattern is wrapped in one of these.
 *
 * In both types of groupings, a vertical bar | denotes a random choice.
 * Empty groups are allowed. For example, "(foo|bar)" emits either "foo"
 * or "bar". The pattern "<c|v|>" emits a constant, vowel, or nothing at
 * all.
 *
 * An exclamation point ! means to capitalize the component that follows
 * it. For example, "!(foo)" will emit "Foo" and "v!s" will emit a
 * lowercase vowel followed by a capitalized syllable, like "eRod".
 *
 * This library is based on the RinkWorks Fantasy Name Generator.
 * http://www.rinkworks.com/namegen/
 */
#ifndef NAMEGEN_H
#define NAMEGEN_H

/* Return codes */
#define NAMEGEN_SUCCESS    0  /**< No errors */
#define NAMEGEN_TRUNCATED  1  /**< Output was truncated */
#define NAMEGEN_INVALID    2  /**< Pattern is invalid */
#define NAMEGEN_TOO_DEEP   3  /**< Pattern exceeds maximum nesting depth */

int namegen(char *, unsigned long, const char *, unsigned long *);

#endif
