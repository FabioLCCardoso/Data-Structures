class Solution {


    fun getPowers(n: Int, x : Int): List<Int>{
        val powers = mutableListOf<Int>()
        var base = 1
        while(true){
            val value = base.toDouble().pow(x).toLong()
            if (value > n) break
            powers.add(value.toInt())
            base ++
        }
        return powers
    }


    fun numberOfWays(n: Int, x: Int): Long {
        val MOD = 1_000_000_007L 
        val powers = getPowers(n, x)

        val dp = LongArray(n + 1)
        dp[0] = 1

        for(p in powers){
            for(s in n downTo p){
                dp[s] = (dp[s] + dp[s - p]) % MOD
            }
        }
        
        
    return dp[n]
    }
}
