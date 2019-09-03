### 思路1 使用递归

注意题目并没有叫我们实现移动的过程，而只是求出移动的次数。

找出递归方程。我们假设把K个圆盘从第一根柱子移动到第三根柱子需要F(K)次。那么移动K-1个圆盘到第三根柱子要F(K-1)次。

再来看看F(K)的组成，首先是把除了最底最大的之外的K-1个圆盘从第一根柱子移动到第三根柱子，由上分析，是F(K-1)次。然后把最大圆盘移动到中间，是一次。再把K-1个圆盘从最右边移动到最左边，是F(K-1)次。再把最大圆盘从中间移动到右边，是一次。最后再把左边的K-1圆盘移动到右边，又是F(K-1)次。所以F(K) = 3 * F(K-1) + 2。

最后再来看看递归的出口。只有一个盘子的时候，我们要移动两次，所以出口就是F(1) = 2。