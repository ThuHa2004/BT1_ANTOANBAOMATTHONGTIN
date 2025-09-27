// Hàm tạo ma trận khóa 5x5 từ khóa nhập
function taoMaTranKhoa(khoa) {
  khoa = khoa.toUpperCase().replace(/J/g, "I");
  let bangChuCai = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
  let maTran = [];
  let chuDaDung = "";

  for (let c of khoa) {
    if (!chuDaDung.includes(c) && bangChuCai.includes(c)) {
      chuDaDung += c;
    }
  }
  for (let c of bangChuCai) {
    if (!chuDaDung.includes(c)) {
      chuDaDung += c;
    }
  }

  for (let i = 0; i < 25; i += 5) {
    maTran.push(chuDaDung.slice(i, i + 5).split(""));
  }
  return maTran;
}

// Hiển thị ma trận khóa trên giao diện
function hienThiMaTran(maTran) {
  let container = document.getElementById("matrixContainer");
  container.innerHTML = "<h3>Ma trận khóa 5x5:</h3>";
  let grid = document.createElement("div");
  grid.className = "matrix";
  maTran.flat().forEach(ch => {
    let cell = document.createElement("div");
    cell.className = "cell";
    cell.textContent = ch;
    grid.appendChild(cell);
  });
  container.appendChild(grid);
}

// Hàm tìm vị trí ký tự trong ma trận
function timViTri(maTran, chu) {
  for (let i = 0; i < 5; i++) {
    for (let j = 0; j < 5; j++) {
      if (maTran[i][j] === chu) return [i, j];
    }
  }
  return null;
}

// Tiền xử lý văn bản: tạo cặp, giữ nguyên khoảng trắng
function xuLyCap(vanBan) {
  vanBan = vanBan.toUpperCase().replace(/J/g, "I");
  let cap = [];
  let i = 0;

  while (i < vanBan.length) {
    let a = vanBan[i];
    if (a < "A" || a > "Z") { // ký tự không phải chữ
      cap.push([a, null]); // giữ lại
      i++;
      continue;
    }

    let b = (i + 1 < vanBan.length) ? vanBan[i + 1] : "X";
    if (a === b) {
      cap.push([a, "X"]);
      i++;
    } else {
      if (b && b >= "A" && b <= "Z") {
        cap.push([a, b]);
        i += 2;
      } else {
        cap.push([a, "X"]);
        i++;
      }
    }
  }
  return cap;
}

// Hàm mã hóa
function maHoa() {
  let khoa = document.getElementById("key").value;
  let vanBan = document.getElementById("plaintext").value;
  let maTran = taoMaTranKhoa(khoa);
  hienThiMaTran(maTran);

  let cap = xuLyCap(vanBan);
  let ketQua = "";

  cap.forEach(([a, b]) => {
    if (b === null) { // ký tự đặc biệt hoặc khoảng trắng
      ketQua += a;
      return;
    }

    let [r1, c1] = timViTri(maTran, a);
    let [r2, c2] = timViTri(maTran, b);

    if (r1 === r2) {
      ketQua += maTran[r1][(c1 + 1) % 5];
      ketQua += maTran[r2][(c2 + 1) % 5];
    } else if (c1 === c2) {
      ketQua += maTran[(r1 + 1) % 5][c1];
      ketQua += maTran[(r2 + 1) % 5][c2];
    } else {
      ketQua += maTran[r1][c2];
      ketQua += maTran[r2][c1];
    }
  });

  document.getElementById("output").textContent = ketQua;
}

// Hàm giải mã
function giaiMa() {
  let khoa = document.getElementById("key").value;
  let vanBan = document.getElementById("plaintext").value.toUpperCase().replace(/J/g, "I");
  let maTran = taoMaTranKhoa(khoa);
  hienThiMaTran(maTran);

  let ketQua = "";
  let i = 0;

  while (i < vanBan.length) {
    let a = vanBan[i];
    if (a < "A" || a > "Z") { // ký tự không phải chữ
      ketQua += a;
      i++;
      continue;
    }

    let b = vanBan[i + 1];
    if (!b || b < "A" || b > "Z") {
      b = "X"; // thêm X nếu lẻ
    }

    let [r1, c1] = timViTri(maTran, a);
    let [r2, c2] = timViTri(maTran, b);

    if (r1 === r2) {
      ketQua += maTran[r1][(c1 + 4) % 5];
      ketQua += maTran[r2][(c2 + 4) % 5];
    } else if (c1 === c2) {
      ketQua += maTran[(r1 + 4) % 5][c1];
      ketQua += maTran[(r2 + 4) % 5][c2];
    } else {
      ketQua += maTran[r1][c2];
      ketQua += maTran[r2][c1];
    }

    i += 2;
  }

  // Loại bỏ X thừa: giữa 2 chữ giống nhau hoặc cuối chuỗi
  ketQua = ketQua.replace(/([A-Z])X(?=\1)/g, "$1");
  ketQua = ketQua.replace(/X$/g, "");

  document.getElementById("output").textContent = ketQua;
}
