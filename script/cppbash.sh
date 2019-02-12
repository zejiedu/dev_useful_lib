#对所有用户有效修改/etc/profile
#对个人有效则修改~/.bashrc


#在PATH中找到可执行文件程序的路径。
export PATH =$PATH:$HOME/bin  

#gcc找到头文件的路径
C_INCLUDE_PATH=$C_INCLUDE_PATH:/MyLib  
export C_INCLUDE_PATH  

#g++找到头文件的路径
CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/MyLib  
export CPLUS_INCLUDE_PATH


#找到动态链接库的路径
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/MyLib  
export LD_LIBRARY_PATH  

#找到静态库的路径
LIBRARY_PATH=$LIBRARY_PATH:/MyLib  
export LIBRARY_PATH  


#下面是在gcc命令中手动设置搜索路径：
#添加头文件搜索路径
# gcc foo.c -I /home/xiaowp/include -o foo 
#添加动态库搜索路径
# gcc foo.c -L /home/xiaowp/lib -lfoo -o foo  
#添加静态库搜索路径
# gcc foo.c -L /home/xiaowp/lib -static -lfoo -o foo 



