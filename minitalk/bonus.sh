mkdir srcs_bonus
cp srcs/* srcs_bonus/
for f in srcs_bonus/*.h; do mv -- "$f" "${f%.h}_bonus.h"; done;
for f in srcs_bonus/*.c; do mv -- "$f" "${f%.c}_bonus.c"; done;
sed -i '' -e "s/MINITALK_H/MINITALK_BONUS_H/g" srcs_bonus/*.h
sed -i '' -e "s/minitalk.h/minitalk_bonus.h/g" srcs_bonus/*.c
echo "Bonus directory made."
