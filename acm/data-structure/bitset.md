常用的成员函数：  
b.any() b中是否存在置为1的二进制位？  
b.none() b中不存在置为1的二进制位吗？  
b.count() b中置为1的二进制位的个数  
b.size() b中二进制位数的个数  
b[pos] 访问b中在pos处二进制位  
b.test(pos) b中在pos处的二进制位置为1么？  
b.set() 把b中所有二进制位都置为1  
b.set(pos) 把b中在pos处的二进制位置为1  
b.reset( ) 把b中所有二进制位都置为0  
b.reset( pos ) 把b中在pos处的二进制位置置为0  
b.flip( ) 把b中所有二进制位逐位取反  
b.flip( pos ) 把b中在pos处的二进制位取反  
b.to_ulong( ) 把b中同样的二进制位返回一个unsigned  
os << b 把b中的位集输出到os流  
