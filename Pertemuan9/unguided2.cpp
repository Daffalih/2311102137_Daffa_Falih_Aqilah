//Daffa Falih Aqilah
//2311102137

#include <iostream>
#include <iomanip>

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() // inisialisasi
{
    root = NULL;
}

bool isEmpty() // cek apakah tree kosong
{
    return root == NULL;
}

void buatNode(char data) // membuat node root
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root!" << endl;
    }
    else
    {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon *findNode(Pohon *node, char data) // mencari node
{
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    Pohon *foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);

    return foundNode;
}

Pohon *insertLeft(char data, Pohon *node) // menambah child kiri
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) // menambah child kanan
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) // mengupdate node
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void find(Pohon *node) // mencari node dan menampilkan informasi node
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

void printChild(Pohon *node) // menampilkan child
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        if (node->left)
        {
            cout << "Child Kiri: " << node->left->data << endl;
        }
        else
        {
            cout << "Child Kiri: (tidak ada)" << endl;
        }

        if (node->right)
        {
            cout << "Child Kanan: " << node->right->data << endl;
        }
        else
        {
            cout << "Child Kanan: (tidak ada)" << endl;
        }
    }
}

void printDescendants(Pohon *node) // menampilkan descendants
{
    void preOrder(Pohon * node);

    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "Descendants dari node " << node->data << " : ";
        if (node->left) preOrder(node->left);
        if (node->right) preOrder(node->right);
        cout << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}


// inOrder
void inOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
    cout << endl;
}

// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    init();
    char Choice_137, Data_137, Direction_137, ParentData_137;
    Pohon *node;

    cout << "\n TREE PROGRAM \n";

    do
    {
        cout << "\nMenu: ";
        cout << "\n1. Buat Node Root";
        cout << "\n2. Tambah Child (kiri/kanan)";
        cout << "\n3. Update Node";
        cout << "\n4. Characteristics";
        cout << "\n5. Find Node";
        cout << "\n6. PreOrder Traversal";
        cout << "\n7. InOrder Traversal";
        cout << "\n8. PostOrder Traversal";
        cout << "\n9. Print Child";
        cout << "\n0. Print Descendants";
        cout << "\nPilihlah: "; cin >> Choice_137;

        switch (Choice_137)
        {
        case '1': // case ini digunakan untuk membuat node root
            cout << "\nOke sip, mulai dari root! Input data untuk rootnya: ";
            cin >> Data_137;
            buatNode(Data_137);
            break;

        case '2': // case ini digunakan untuk menambah child
            cout << "\nMasukkan data untuk child: ";
            cin >> Data_137;
            cout << "\nChild yang diinput berada di posisi (Left (L/l) / Right (R/r)): ";
            cin >> Direction_137;
            cout << "\nMasukkan data dari parent node: ";
            cin >> ParentData_137;
            node = findNode(root, ParentData_137);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_137 << " tidak ditemukan!" << endl;
            }
            else
            {
                if (Direction_137 == 'L' || Direction_137 == 'l')
                {
                    insertLeft(Data_137, node);
                }
                else if (Direction_137 == 'R' || Direction_137 == 'r')
                {
                    insertRight(Data_137, node);
                }
                else
                {
                    cout << "\nHah! Pilihan tidak valid!" << endl;
                }
            }
            break;

        case '3': // case ini digunakan untuk mengupdate node
            cout << "\nMasukkan data baru untuk diupdate: ";
            cin >> Data_137;
            cout << "\nMasukkan data dari node yang ingin diupdate: ";
            cin >> ParentData_137;
            node = findNode(root, ParentData_137);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_137 << " tidak ditemukan!" << endl;
            }
            else
            {
                update(Data_137, node);
            }
            break;

        case '4': // case ini digunakan untuk menampilkan karakteristik tree
            cout << "\nKarakteristik dari tree ini:";
            characteristic();
            break;

        case '5': // case ini digunakan untuk mencari node
            cout << "\nMasukkan data dari node yang ingin dicari: ";
            cin >> ParentData_137;
            node = findNode(root, ParentData_137);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_137 << " tidak ditemukan!" << endl;
            }
            else
            {
                find(node);
            }
            break;

        case '6': // case ini digunakan untuk preOrder traversal
            cout << "\nPreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;

        case '7': // case ini digunakan untuk inOrder traversal
            cout << "\nInOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;

        case '8': // case ini digunakan untuk postOrder traversal
            cout << "\nPostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;

        case '9': // case ini digunakan untuk print child
            cout << "\nMasukkan data dari node yang ingin melihat child: ";
            cin >> ParentData_137;
            node = findNode(root, ParentData_137);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_137 << " tidak ditemukan!" << endl;
            }
            else
            {
                printChild(node);
            }
            break;

        case '0': 
            cout << "\nMasukkan data dari node yang ingin melihat descendants: ";
            cin >> ParentData_137;
            node = findNode(root, ParentData_137);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_137 << " tidak ditemukan!" << endl;
            }
            else
            {
                printDescendants(node);
            }
            break;

        default:
            cout << "\nERROR." << endl;
            break;
        }
    } while (Choice_137 != '!');
    cout << "\nSelesai" << endl;

    return 0;
}
