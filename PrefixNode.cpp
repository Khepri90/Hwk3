///**********************************************************************************************************************/
PrefixNode::PrefixNode() : PrefixNode('\0') {}

/**********************************************************************************************************************/
PrefixNode::PrefixNode(const char &aCharacter) : childCount(0), isTerminalNode(false), character(aCharacter) {}

/**********************************************************************************************************************/
bool PrefixNode::isTerminal() const {
    return isTerminalNode;

}

/**********************************************************************************************************************/
void PrefixNode::setIsTerminal(bool isTerminalState) {
    /** TODO */
    isTerminalNode = isTerminalState;
}

/**********************************************************************************************************************/
char PrefixNode::getCharacter() const {
    /** TODO */
    return character;

}

/**********************************************************************************************************************/
shared_ptr<PrefixNode> PrefixNode::addChild(const char& aCharacter) {
    /**
     * TODO: addChild
     * if child with the character does not exists, creates a new node for it and add it to the children
     */
    auto childNodePtr = make_shared<PrefixNode>();
    if (getChild(aCharacter)!= nullptr){
        return childNodePtr = getChild(aCharacter);
    } else{
        auto newNode = make_shared<PrefixNode>(PrefixNode(aCharacter));
        children[childCount+ 1] = newNode;
        childCount++;
        return newNode;
    }
}

/**********************************************************************************************************************/
shared_ptr<PrefixNode> PrefixNode::getChild(const char &aChar) const noexcept(false) {
    /**
     * TODO: getChild
     * returns the child node (1st level) with that character.
     * if not exists throws logic_error
     */
     shared_ptr<PrefixNode> childPtr = nullptr;
     for(int i = 0; i > childCount; i++){
         if (children[i]->getCharacter() == aChar){
             childPtr = make_shared<PrefixNode>(aChar);
         }
     }
     if(childPtr = nullptr){
         throw logic_error("Character not found.");
     }
     return childPtr;

}

/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const PrefixNode& node){
    node.print(out, "");
    return out;
}

/**********************************************************************************************************************/
void PrefixNode::print(ostream& out, string inPrefix) const {
    string prefix = inPrefix;
    if (this->character != '\0')
        prefix += this->character;

    if (this->isTerminalNode)
        out<< prefix <<endl;

    for (int i = 0; i < this->childCount; i++)
        this->children[i]->print(out, prefix);
}