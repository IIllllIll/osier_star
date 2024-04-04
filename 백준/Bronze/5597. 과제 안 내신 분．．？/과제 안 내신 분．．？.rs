use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut arr:[i64;31] = [1;31];

  for _ in 0..28{
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();

    arr[n]-=1;
  }

  for i in 1..31{
    if arr[i]!=0{
      writeln!(out,"{}",i);
    }
  }
}