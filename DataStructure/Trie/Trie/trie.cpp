#include "trie.h"
TrieNode *GetNode() {
	TrieNode *p_node = NULL;
	p_node = (TrieNode *)malloc(sizeof(TrieNode));
	if (p_node) {
		p_node->value = 0;
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			p_node->children[i] = NULL;
		}
	}
	return p_node;
}

void Initialize(Trie *p_trie) {
	p_trie->root = GetNode();
	p_trie->count = 0;
}

void Insert(Trie *p_trie, std::string key) {
	int length = key.size();
	TrieNode *p_crawl;
	++p_trie->count;
	p_crawl = p_trie->root;
	for (int level = 0; level < length; ++level) {
		int index = CHAR_TO_INDEX(key[level]);
		if (!p_crawl->children[index]) {
			p_crawl->children[index] = GetNode();
		}
		p_crawl = p_crawl->children[index];
	}
	p_crawl->value = p_trie->count;
}

int Search(Trie *p_trie, std::string key) {
	int length = key.size();
	TrieNode *p_crawl = p_trie->root;
	for (int level = 0; level < length; ++level) {
		int index = CHAR_TO_INDEX(key[level]);
		if (!p_crawl->children[index]) {
			return 0;
		}
		p_crawl = p_crawl->children[index];
	}
	return (NULL != p_crawl && p_crawl->value);
}
int main() {
	std::string keys[8] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
	Trie trie;
	Initialize(&trie);
	for (int i = 0; i < ARRAY_SIZE(keys); ++i) {
		Insert(&trie, keys[i]);
	}
	 // Search for different keys
	printf("%s --- %d\n", "the", Search(&trie, "the"));
    printf("%s --- %d\n", "these", Search(&trie, "these"));
	printf("%s --- %d\n", "their", Search(&trie, "their"));
	printf("%s --- %d\n", "thaw", Search(&trie, "thaw"));
	getchar();
	return 0;
}