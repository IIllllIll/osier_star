use std::{io::{stdin,stdout,Write,BufWriter}};

fn abs(a:i32)->i32{
  if a>=0{
    return a;
  }
  else{
    return -a;
  }
}

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let n = input.trim().parse::<i64>().unwrap();

  let mut a=0;
  let mut b=0;
  let mut flag :bool = false;
  for _ in 0..n{
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let input = input.trim();

    if flag {
      continue;
    }

    if input=="D"{
      a+=1;
    }
    else{
      b+=1;
    }

    if abs(a-b)==2{
      flag = true;
    }
  }
  writeln!(out,"{}:{}",a,b);
}