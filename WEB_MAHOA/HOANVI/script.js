// parse permutation string to zero-based array
function parsePerm(s) {
  if (!s) return [];
  s = s.replace(/,/g, ' ').trim();
  if (s === '') return [];
  let parts = s.split(/\s+/);
  let perm = [];
  for (let p of parts) {
    let v = parseInt(p, 10);
    if (isNaN(v)) return []; // invalid token
    perm.push(v - 1); // convert to 0-based
  }
  return perm;
}

// validate perm array is true permutation of [0..n-1]
function isValidPermutation(perm) {
  if (!perm || perm.length === 0) return false;
  let n = perm.length;
  let seen = new Array(n).fill(false);
  for (let i = 0; i < n; ++i) {
    let v = perm[i];
    if (typeof v !== 'number' || v < 0 || v >= n) return false;
    if (seen[v]) return false;
    seen[v] = true;
  }
  return seen.every(x => x);
}

function padBlock(block, n, padchar) {
  while (block.length < n) block += padchar;
  return block;
}

// Encryption mapping: c[ perm[i] ] = b[i]
function encrypt(plain, perm, padchar = 'X') {
  let n = perm.length;
  if (n === 0) return '';
  let out = '';
  for (let i = 0; i < plain.length; i += n) {
    let block = plain.slice(i, i + n);
    block = padBlock(block, n, padchar);
    let cblock = new Array(n).fill('');
    for (let j = 0; j < n; ++j) cblock[perm[j]] = block[j];
    out += cblock.join('');
  }
  return out;
}

// Decrypt mapping: b[i] = c[ perm[i] ]
function decrypt(cipher, perm) {
  let n = perm.length;
  if (n === 0) return '';
  let padded = cipher;
  if (cipher.length % n !== 0) padded = padBlock(cipher, Math.ceil(cipher.length / n) * n, 'X');
  let out = '';
  for (let i = 0; i < padded.length; i += n) {
    let cblock = padded.slice(i, i + n);
    let pblock = new Array(n).fill('');
    for (let j = 0; j < n; ++j) pblock[j] = cblock[perm[j]] || '';
    out += pblock.join('');
  }
  return out.replace(/X+$/, '');
}

// UI elements
const inputText = document.getElementById('inputText');
const permInput = document.getElementById('permInput');
const encBtn = document.getElementById('encBtn');
const decBtn = document.getElementById('decBtn');
const output = document.getElementById('output');
const msg = document.getElementById('msg');

function showMessage(text) {
  if (!text) { msg.style.display = 'none'; msg.textContent = ''; return; }
  msg.style.display = 'block';
  msg.textContent = text;
}

function handleEncrypt() {
  showMessage('');
  const text = inputText.value || '';
  if (text.trim() === '') { showMessage('Nhap input text truoc.'); return; }
  const perm = parsePerm(permInput.value);
  if (!isValidPermutation(perm)) {
    showMessage('Permutation khong hop le. Phai la hoan vi cua 1..n (cac so 1..n moi xuat hien 1 lan).');
    return;
  }
  try {
    const cipher = encrypt(text, perm, 'X');
    output.textContent = cipher;
  } catch (e) {
    showMessage('Loi khi ma hoa: ' + (e && e.message ? e.message : e));
    console.error(e);
  }
}

function handleDecrypt() {
  showMessage('');
  const text = inputText.value || '';
  if (text.trim() === '') { showMessage('Nhap input text truoc.'); return; }
  const perm = parsePerm(permInput.value);
  if (!isValidPermutation(perm)) {
    showMessage('Permutation khong hop le. Phai la hoan vi cua 1..n (cac so 1..n moi xuat hien 1 lan).');
    return;
  }
  try {
    const dec = decrypt(text, perm);
    output.textContent = dec;
  } catch (e) {
    showMessage('Loi khi giai ma: ' + (e && e.message ? e.message : e));
    console.error(e);
  }
}

// attach handlers
encBtn.addEventListener('click', handleEncrypt);
decBtn.addEventListener('click', handleDecrypt);

// optional: allow Enter key in permInput to trigger Encrypt
permInput.addEventListener('keydown', (ev) => {
  if (ev.key === 'Enter' && !ev.shiftKey) {
    ev.preventDefault();
    handleEncrypt();
  }
});

// helper: clear messages when editing
inputText.addEventListener('input', () => showMessage(''));
permInput.addEventListener('input', () => showMessage(''));
