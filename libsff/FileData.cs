using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace libsff
{
    class CALC1
    {
        bool fSuc_ = false;
        byte[] bf_ = new byte[10];
        byte[] bc_ = new byte[10];
        byte[] bl_ = new byte[10];


        public CALC1()
        {
            Array.Clear(bf_, 0, bf_.Length);
            Array.Clear(bc_, 0, bc_.Length);
            Array.Clear(bl_, 0, bl_.Length);
        }

        public uint  calcitt(string name)
        {
            FileInfo fi = new FileInfo(name);
            long len = fi.Length;

            using (FileStream fs = fi.OpenRead())
            {
                if (len < 20)
                {
                    fs.Position = 0;
                    fs.Read(bf_, 0, bf_.Length);
                    Array.Copy(bf_, bc_, bf_.Length);
                    Array.Copy(bf_, bl_, bf_.Length);
                    fSuc_ = true;
                    return 0;
                }

                int readed = fs.Read(bf_, 0, bf_.Length);
                if (readed != bf_.Length)
                    return 1;

                long halflen = len / 2;
                fs.Position = halflen;
                readed = fs.Read(bc_, 0, bc_.Length);
                if (readed != bc_.Length)
                    return 1;

                long lenm10 = len - 10;
                fs.Position = lenm10;
                readed = fs.Read(bl_, 0, bl_.Length);
                if (readed != bl_.Length)
                    return 1;

                fSuc_ = true;
                return 0;
            }
        }

        // https://stackoverflow.com/a/311179
        static string ByteArrayToString(byte[] ba)
        {
            string hex = BitConverter.ToString(ba);
            return hex.Replace("-", "");
        }
        public string getCalc(long leng)
        {
            if (!fSuc_)
                return string.Empty;

            StringBuilder sbret = new StringBuilder();
            sbret.Append(leng.ToString());
            sbret.Append("-");

            sbret.Append(ByteArrayToString(bf_));
            sbret.Append(ByteArrayToString(bc_));
            sbret.Append(ByteArrayToString(bl_));

            return sbret.ToString();
        }
        
    };
    class FileData
    {
        string name_;
        long leng_;
        int orgdir_;
        CALC1 c1_;

        public FileData(int origindex, string dir, string part, long leng)
        {
            name_ = Path.Combine(dir, part);
            leng_ = leng;
        }
        public long Length
        {
            get { return leng_; }
        }
        public string Name
        {
            get { return name_; }
        }
        
        public uint GetCalculate1(ref string ret)
        {
            if (c1_ == null)
            {
                c1_ = new CALC1();
                uint dw = c1_.calcitt(name_);
                if (dw != 0)
                    return dw;
            }
            ret = c1_.getCalc(leng_);
            return 0;
        }
        public int OrigIndex
        {
            get { return OrigIndex; }
        }
    }

  
}
