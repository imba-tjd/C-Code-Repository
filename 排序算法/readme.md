# 本部分代码的特点

* 参数中的数组
  * 如果只有一个数组，顺序为arr, len或arr, from, to；前者必为左闭右开，后者必不把数组进行指针算数运算
  * 如果有两个以上数组，顺序为len1, arr1[len1], len2, arr2[len2]，不把数组进行指针算数运算
  * 偶尔有C++风格：arr, *end
* 使用了VLA
* 测试用的数组长度是硬编码的10，不打算用sizeof(arr)/sizeof(*arr)；数据也是硬编码的随机数据，不打算从用户处读入
* 参数泛型硬编码为int

总之重点在于排序的思想。
