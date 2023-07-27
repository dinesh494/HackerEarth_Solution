#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define BUFFER_SIZE 10240
 
static char buffer[BUFFER_SIZE + 1];
char *bact = buffer;
char *bend = buffer;
char *btail = buffer;
 
FILE *in, *out;
 
void buf_read_next_chunk()
{
    size_t rem_bytes = bend - bact;
    if (rem_bytes > 0)
    {
        memcpy(buffer, bact, rem_bytes);
    }
    bact = buffer;
 
    size_t bytes_read = fread(bact + rem_bytes, 1, BUFFER_SIZE - rem_bytes, in);
    bend = bact + rem_bytes + bytes_read;
    if (feof(in))
    {
        *bend++ = ' ';
    }
 
    for (btail = bend - 1; *btail >= '0' && *btail <= '9'; --btail)
    {
    }
}
 
void buf_write_next_chunk()
{
    size_t bytes_in_buf = bact - buffer;
    if (bytes_in_buf > 0)
    {
        fwrite(buffer, 1, bytes_in_buf, out);
        bact = buffer;
    }
}
 
void buf_write_flush()
{
    size_t bytes_in_buf = bact - buffer;
    if (bytes_in_buf > 0)
    {
        fwrite(buffer, 1, bytes_in_buf, out);
    }
}
 
int read_int()
{
    for (; bact < btail && *bact != '-' && (*bact < '0' || *bact > '9'); ++bact)
    {
    }
    if (bact == btail)
    {
        buf_read_next_chunk();
        for (; *bact != '-' && (*bact < '0' || *bact > '9'); ++bact)
        {
        }
    }
 
    int neg = 0;
    if (*bact == '-')
    {
        neg = 1;
        bact++;
    }
 
    int result = 0;
    do
    {
        result = result * 10 + *bact++ - '0';
    } while (*bact >= '0' && *bact <= '9');
 
    return neg ? -result : result;
}
 
void write_str(char *s, size_t l)
{
    if ((size_t)(bend - bact) < l)
    {
        fwrite(buffer, 1, bact - buffer, out);
        bact = buffer;
    }
 
    memcpy(bact, s, l);
    bact += l;
}
 
void write_int(int x)
{
    static char num_buf[11] = "           ";
    static char *num_buf_end = num_buf + sizeof(num_buf) - 1;
 
    int neg = 0;
    if (x < 0)
    {
        neg = 1;
        x = -x;
    }
 
    char *b = num_buf_end;
    do
    {
        *(--b) = x % 10 + '0';
        x /= 10;
    } while (x != 0);
 
    if (neg)
    {
        *(--b) = '-';
    }
 
    write_str(b, num_buf_end - b + 1);
}
 
int main()
{
    in = stdin;
    out = stdout;
 
    int i, j;
 
    int n, m, k;
    n = read_int();
    m = read_int();
    k = read_int();
 
    int mat_elements = n * m;
    int mat_bytes = mat_elements * sizeof(int);
    int *mat = malloc(mat_bytes << 1);
    int *delta = mat + mat_elements;
 
    int *m_act = mat;
    for (i = 0; i < mat_elements; i++)
    {
        *m_act++ = read_int();
    }
 
    memset(delta, 0, mat_bytes);
    for (i = 0; i < k; i++)
    {
        int r, c, s, d;
        r = read_int();
        c = read_int();
        s = read_int();
        d = read_int();
 
        --r;
        --c;
 
        int *delta_row = delta + r * m;
        for (j = 0; j < s; j++)
        {
            delta_row[c] += d;
            if (c + s < m)
            {
                delta_row[c + s] -= d;
            }
            delta_row += m;
        }
    }
 
    bact = buffer;
    bend = buffer + BUFFER_SIZE;
 
    m_act = mat;
    int *d_act = delta;
    for (i = 0; i < n; i++)
    {
        int d = 0;
        for (auto j = 0; j < m; j++)
        {
            d += *d_act++;
            write_int((*m_act++) + d);
        }
        write_str("\n", 1);
    }
 
    buf_write_flush();
 
    return 0;
}