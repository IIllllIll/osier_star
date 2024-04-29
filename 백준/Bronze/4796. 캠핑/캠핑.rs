use std::{io::{stdin,stdout,Write,BufWriter}};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  
  //let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let mut idx=0;
  while true {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut n = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
    idx+=1;
    let a = n.next().unwrap();
    let b = n.next().unwrap();
    let c = n.next().unwrap();
    
    if a==0&&b==0&&c==0{
      break;
    }
    let mut ans = ((c/b)*a);
    if c%b<=a{
      ans+=c%b;
    }
    else{
      ans+=a;
    }
    writeln!(out,"Case {}: {}",idx,ans);
  }
}