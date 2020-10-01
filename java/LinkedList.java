class Node{
  int data;
  Node next;
  public Node(int d){
    this.data=d;
  }
}
class LinkedList{
  int size;
  Node head;
  LinkedList(){
    this.size=0;
  }
  public void addNode(int x){
    if (head==null){
      head = new Node(x);
      size++;
      return;}
     else{
    Node curr=head;
    while(curr.next!=null){
       curr=curr.next;
    }
    curr.next=new Node(int x);
    size++;
    return;}
