通过将key mod n 从而使key离散散列在[0,n-1]中，那么一般推荐n为素数,因为如果选n=a * b，那么如果key=a * x则key mod n = a * y，其中0<=y<b，那么key就不是均匀散列了，冲突率增加。
