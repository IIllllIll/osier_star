use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let mut a = input.next().unwrap();
  let mut b = input.next().unwrap();

  if a-b<0{
    writeln!(out,"{}",-1*(a-b));
  }
  else{
    writeln!(out,"{}",a-b);
  }
}