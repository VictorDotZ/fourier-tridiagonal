```bash
plot "f_out.txt" using 1:2 w lp title "fourie", "f_out.txt" using 1:3 w lp title "true", "t_out.txt" u 1:2 w lp title "tridiagonal"
```

```bash
./tridiagonal.out 10 t_out.txt >> t_err.txt
./tridiagonal.out 100 t_out.txt >> t_err.txt
./tridiagonal.out 1000 t_out.txt >> t_err.txt
./tridiagonal.out 10000 t_out.txt >> t_err.txt
```

```bash
plot "t_err.txt" u (log10($1)):(log10(1/$2)) pointtype 5 notitle, 2*x with lines title "y=2x"
```