/*
39设有一个正整数序列组成的有序单链表(按递增次序有序,且允许有相等的整数存在),
试编写能实现下列功能的算法(要求用最少的时间和最小的空间)
(1)确定在序列中比正整数x大的数有几个(相同的数只计算一次,如序列{20,20,17,16,15,15,11,10,8,7,7,5,4}中比10大的数有5个)
(2)在单链表将比正整数x小的数按递减次序排列;
(3)将正整数(比)x大的偶数从单链表中删除。
【东北大学2001二(17分)】
*/

/*分析
在由正整数序列组成的有序单链表中,数据递增有序,允许相等整数存在。确
定比正整数x大的数有几个属于计数问题,相同数只计一次,要求记住前驱,前驱和后继
值不同时移动前驱指针,进行计数。将比正整数x小的数按递减排序,属于单链表的逆置
问题。比正整数x大的偶数从表中删除,属于单链表中结点的删除,必须记住其前驱,以
使链表不断链。算法结束时,链表中结点的排列是:小于x的数按递减排列,接着是x(若
有的话),最后是大于x的奇数。
*/

void exam(LinkedList la, int x)
{	//本算法确定比x大的数有几个;将比x小的数按递减排序,并将比x大的偶数从链表中删除
 	p=1a->next;q=p;//p为工作指针,q指向最小值元素,其可能的后继将是大于等于x的第一个元素
	pre=la;			//pre为p的前驱结点指针
 	k=0;			//计数(比x大的数)
 	1a->next=nu11;	//置空单链表表头拮点

 	while(p&&p->data<x)//先解决比x小的数按递减次序排列
 	{
		r=p->next;//暂存后继
   		 p->next=1a->next;//逆置
		1a->next=p;
		p=r;//恢复当前指针。退出循环时,r指向值大于等于x的拮点
 	}
	q->next=p; pre=q;//pre指向结点的前驱结点

	while(p->data=x)
	{
		pre=p;p=p->next;//从小于x到大于x可能经过等于x
	}

	while(p)//以下结点的数据域的值均大于x
	{
		k++; x=p->data;//下面用x表示数据域的值,计数
		if(x%2==0)//删偶数
  	 	{
   		    whi1e(p->data==x)
   		    {
   		      u=p;p=p->next;free(u);
   		    }//删相等偶数
			pre->next=p;//拉上链
		}
		else//处理奇数
			whie(p->data==x)
			{
			  pre->next=p;pre=p;p=p->next;
			}//相同数只记一次
	}//while(p)
	printf("比值%d大的数有%d个\n",x,k);
}//算法exam结束