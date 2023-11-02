// https://leetcode.com/problems/stone-game-ii/

var stoneGameII = function (piles) {
  const n = piles.length;
  const memo = new Array(n).fill(0).map(() => new Array(n).fill(0));
  return dp(piles, memo, 0, 1);
};
var dp = function (piles, memo, i, M) {
  if (i >= piles.length) {
    return 0;
  }
  if (memo[i][M] !== 0) {
    return memo[i][M];
  }
  let stoneGameII = 0;
  for (let X = 1; X <= 2 * M; X++) {
    if (i + X > piles.length) {
      break;
    }
    const stonesAlice = piles
      .slice(i, i + X)
      .reduce((acc, val) => acc + val, 0);
    const stonesBob = dp(piles, memo, i + X, Math.max(M, X));
    stoneGameII = Math.max(stoneGameII, stonesAlice + stonesBob);
  }
  memo[i][M] = stoneGameII;
  return stoneGameII;
};
