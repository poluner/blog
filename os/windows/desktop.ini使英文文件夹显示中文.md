就像文档文件夹一样，看起来是中文，其实是英文Documents，只需将该文件夹下的配置文件desktop.ini中加入一句话：  
```
LocalizedResourceName=中文名
```
之后重启计算机(win10不必重启，刷新几下就好了)，英文文件夹便变成了中文名。  
但是新建的文件夹不会有desktop.ini文件，需要将文件夹随便更改图标，就会自动生成desktop.ini文件。
