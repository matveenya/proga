// ласс €чейки списка
class Node
{
private:
	double data; //ƒанные в €чейке
	Node* next; //”казатель на следующую €чейку
public:
	~Node();
	Node();
	Node(const Node&);
	double& getData();
	Node* getNext() const;
	void setData(const double&);
	void setNext(Node*);
	Node& operator =(const Node&);
};