#!/bin/bash
rm -rf f_err.txt
./fourie.out 10 f_out.txt >> f_err.txt
./fourie.out 100 f_out.txt >> f_err.txt
./fourie.out 1000 f_out.txt >> f_err.txt

rm -rf t_err.txt
./tridiagonal.out 10 t_out.txt >> t_err.txt
./tridiagonal.out 100 t_out.txt >> t_err.txt
./tridiagonal.out 1000 t_out.txt >> t_err.txt
