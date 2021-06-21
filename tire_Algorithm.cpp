#include<bits/stdc++.h>
using namespace std;


const int MAX_CHAR = 26;

struct Trie {
	Trie* mChild[MAX_CHAR];
	bool mIsLeaf;
	Trie() {
		memset(mChild, 0, sizeof(mChild));
		mIsLeaf = 0;
	}

	void Append(char *pStringInput) {
		if(*pStringInput == '\0')
			mIsLeaf = 1;
		else {
			int cur = *pStringInput - 'a';
			if(mChild[cur] == 0)
				mChild[cur] = new Trie();
			mChild[cur]->Append(pStringInput+1);
		}
	}
	bool prefixExist(char* pStringInput) { //Could use it to suggest moves for player
		if(*pStringInput == '\0')
			return true;

		int cur = *pStringInput - 'a';
		if(mChild[cur] == 0 )
			return false;
		return mChild[cur]->prefixExist(pStringInput+1);
	}
	bool WordExist(char* pStringInput) {
		if(*pStringInput == '\0')
			return mIsLeaf;
		int cur = *pStringInput - 'a';
		if(mChild[cur] == 0 )
			return false;
		return mChild[cur]->WordExist(pStringInput+1);
	}
};





