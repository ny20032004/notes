## 流密码

#### 基本概念

 * 流密码也称为序列密码，每次加密处理数据流的一位或一个字节，加解密使用相同的密钥，是对称密码算法的一种。
 * 流密码的基本思想：利用密钥K产生一个密钥流k1k2…kn对明文流M=m1m2…mn进行如下加密：C=c1c2…cn=Ek1(m1)Ek2(m2)…Ekn(mn)。
 * 1949年Shannon证明只有一次一密是绝对安全的，一次一密的密码方案是流密码的雏形。
 * 若流密码所使用的是真正随机产生的、与消息流长度相同的密钥流，则此时的流密码就是一次一密。

#### RC4

 * 密钥调度算法KSA：

    // K for key.
    for i=0 to N‐1 do
        S[i]=i;
        K[i]=K[i mod L];
    j=0;
    for i=0 to N‐1 do
        j=(j + S[i] + K[i]) mod N;
        swap(S[i], S[j]);

 * 伪随机数生成算法PRGA：

     i,j=0;
    while(true)
        i=(i+1) mod N;
        j=(j+S[i])mod N;
        swap(S[i],S[j]);
        t=(S[i]+S[j])mod N;
        output k=S[t];

 * RC4 加密：明文与秘钥k比特异或
 * RC4 解密：密文与秘钥k比特异或
 