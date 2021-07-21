
/**********************************************************************************************************************/
PrefixTree::PrefixTree() : rootPtr(make_shared<PrefixNode>()) {};

/**********************************************************************************************************************/
void PrefixTree::add(const string &aWord) {
    /**
     * TODO: add public call
     * uses recursion (see add below)
     */
    add(rootPtr, aWord);
}

/**********************************************************************************************************************/
void PrefixTree::add(const shared_ptr<PrefixNode>& ptr, const string &aWord) {
    /**
     * TODO: add (private)
     * recursive call adding the first char of the word, and recursive call with the reminders.
     * Checkout chapter 2 to display word using recursion.
     * Hint: base case len ==1 then the child node is terminal!
     */
    
}


/**********************************************************************************************************************/
bool PrefixTree::isWordInTree(const string &aWord) const {
    /**
     * TODO: isWordInTree
     * iteratively check if the word is in the tree.
     * hint: check character by character as a sequence of chars. also remember that the word is in the tree
     * if once found the word, the last character node is terminal.
     * E.g., if M-A-N-Y with Y terminal is the only one in the tree, MAN is not in the tree as N is not terminal.
     */
     return false;
}

/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const PrefixTree& tree) {
    out << *tree.rootPtr ;
    return out;
}

