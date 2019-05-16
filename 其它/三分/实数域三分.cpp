db l = 0, r = 1e18;
while (r - l > eps) {
    db lmid = l + (r - l) / 3;
		db rmid = l + (r - l) / 3 * 2;
		db tmp = cal(lmid), tmp1 = cal(rmid);
		if (tmp > tmp1)  r = rmid;
		else  l = lmid;
}
ans = l;
