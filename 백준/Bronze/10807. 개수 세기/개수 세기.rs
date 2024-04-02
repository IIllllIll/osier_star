use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let n = input.trim().parse::<i64>().unwrap();

  let mut mp = String::new();
  stdin().read_line(&mut mp).unwrap();
  let mut mp = mp.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let x = input.trim().parse::<i64>().unwrap();
  let mut ans:i64 = 0;

  for _ in 0..n{
    let a = mp.next().unwrap();
    if a==x{
      ans+=1;
    }
  }
  writeln!(out,"{}",ans);
}