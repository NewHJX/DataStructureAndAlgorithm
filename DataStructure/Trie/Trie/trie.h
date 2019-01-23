#ifndef TRIE_TRIE_H_
#define TRIE_TRIE_H_
#include<iostream>
#include<string>
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct TrieNode {
	int value;
	TrieNode *children[ALPHABET_SIZE];
};

struct Trie {
	TrieNode *root;
	int count;
};

TrieNode *GetNode();

void Initialize(Trie *p_trie);

void Insert(Trie *p_trie, std::string key);

int Search(Trie *p_trie, std::string key);

#endif