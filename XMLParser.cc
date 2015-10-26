#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

//given token.next(), which return valid (open,name), (inner, content), (close, name)
class XMLNode {
    string _name;
    string _content="";
    vector<XMLNode*> _children; 
public:
    XMLNode(string name) {
       _name = name; 
    }
    void addContent(string content) {
        _content += content;
    }
    void addChild(XMLNode* child) {
        _children.push_back(child);
    }
    void print(int level) {
        cout <<string(level,' ') <<_name<<endl;
        if(!_content.empty()) cout <<string(level,' ') <<_content<<endl;
        for(XMLNode* child : _children) {
            child->print(level+1);
        }
    }
};

struct XMLElement {
    string type;
    string content;
    XMLElement(string t, string c):type(t),content(c){}
};

struct Token{
    string xml[5][2] = {{"open", "header"},{"open","tag1"},{"inner","hello"},{"close","tag1"},{"close","header"}};
    int ind = 0;
    XMLElement next() {
        //cout <<xml[ind][0]<<xml[ind][1]<<endl;
        return XMLElement(xml[ind][0],xml[ind++][1]);
    }
} token;

void build(XMLNode* parent) {
    XMLElement el = token.next();
    if(el.type == "close") return;
    else if(el.type == "inner") {
        parent->addContent(el.content);
        build(parent);
    } else {
        //open
        XMLNode* node = new XMLNode(el.content);
        build(node);
        parent->addChild(node);
    }
}

XMLNode* build() {
    XMLElement el = token.next();
    if(el.type != "open") return NULL;
    XMLNode *res = new XMLNode(el.content);
    build(res);
    return res;
}

int main() {
    XMLNode* root = build();
    root->print(0);
    return 0;   
}
