use std::{io::{stdin,stdout,Write,BufWriter, Read}};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let d = input.next().unwrap();
  let h = input.next().unwrap();
  let m = input.next().unwrap();
  
  if d<11 {
    write!(out,"-1");
    return;
  }
  else if d==11{
    if h<11{
      write!(out,"-1");
      return;
    }
    else if h==11{
      if m<11{
        write!(out,"-1");
        return;
      }
      else {
        let sum = ((d-11)*(24*60))+((h-11)*60)+(m-11);
        write!(out,"{sum}");
      }
    }
    else {
      let sum = ((d-11)*(24*60))+((h-11)*60)+(m-11);
      write!(out,"{sum}");
    }
  }
  else {
    let sum = ((d-11)*(24*60))+((h-11)*60)+(m-11);
    write!(out,"{sum}");
  }
}