use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());

  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let n = input.next().unwrap();

  if n>=90{
    writeln!(out,"A");
  }
  else if n>=80{
    writeln!(out,"B");
  }
  else if n>=70{
    writeln!(out,"C");
  }
  else if n>=60{
    writeln!(out,"D");
  }
  else {
    writeln!(out,"F");
  }
}