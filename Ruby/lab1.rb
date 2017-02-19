m=nil
while m.class != Fixnum
  puts "Введите натуральное число"
  m = gets
  m = m.to_f
  if m % 1 != 0 || m <= 0
     m=nil
  else
    m = m.to_i
  end
end
puts "\nИскомые числа:"; puts;

def pput(i)
  puts "Десятичная запись: #{i}\nДвоичная запись: #{i.to_s(2)}"
  puts
end

for i in 3..m
  str = i.to_s(2)
  if str[0..1] == "11"
    if str.length == 2
      pput(i)
    end
    str = str[2..-1]
    while str != "" && str.length >= 2
      if str[0..1] == "00" && str.length == 2
        pput(i)
        str = ""
      elsif str.length > 4 && str [0..3] == "0011"
        str = str[4..-1]
      elsif str.length == 4 && str [0..3] == "0011"
        pput(i)
        str = ""
      else
        str = ""
      end
    end
  end
end
