awk -F  ':' "NR>=$FT_LINE1 && NR<=$FT_LINE2 {print \$0}" /etc/passwd
