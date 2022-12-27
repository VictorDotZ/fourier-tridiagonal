```bash
plot "f_out.txt" using 1:2 w lp title "fourie", "f_out.txt" using 1:3 w lp title "true", "t_out.txt" u 1:2 w lp title "tridiagonal"
```

```bash
chmod +x calc_errors.sh
./calc_errors.sh
```

```bash
plot "f_err.txt" u (log10($1)):(log10(1/$2)) pointtype 1 title "fourie", "t_err.txt" u (log10($1)):(log10(1/$2)) pointtype 66 title "tridiagonal",  2*x with lines title "y=2x"
```