using System;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

namespace libsff
{
    public class SffInfo
    {
        int curIndex_;
        System.Text.RegularExpressions.Regex reg_;

        HashSet<string> dupset_ = new HashSet<string>();
        int id_;
        int delay_;
        List<string> dirs_ = new List<string>();
        string curdir_;
        long minleng_;

        bool difforigin_;

        public SffInfo(
            int id,
            int delay,
            List<string> dirs,
            System.Text.RegularExpressions.Regex reg,
            long minleng)
        {
            id_ = id;
            delay_ = delay;
            dirs_ = dirs;
            reg_ = reg;
            minleng_ = minleng;
        }
        int Id
        {
            get { return id_; }
        }
        public bool MoveNext()
        {
            curIndex_++;
            if (dirs_.Count <= curIndex_)
            {
                curdir_ = null;
                return false;
            }

            curdir_ = dirs_[curIndex_];
            return true;
        }
        public bool match(string name)
        {
            if (reg_ == null)
                return true;

            return reg_.IsMatch(name);
        }
        public int CurIndex
        {
            get { return curIndex_; }
        }
        public string CurDir
        {
            get { return curdir_; }
        }
        public bool IsDiffOrigin
        {
            get { return difforigin_; }
        }
        public bool IsProcessedDir(string dir)
        {
            dir = dir.ToLower();
            return dupset_.Contains(dir);
        }
        public void SetProcessedDir(string dir)
        {
            Debug.Assert(!string.IsNullOrEmpty(dir));

            dir = dir.ToLower();
            dupset_.Add(dir);
        }
        public long MinLength
        {
            get { return minleng_; }
        }
    }

    public class Sff
    {
        Dictionary<long, FileData> alcheck1_ = new Dictionary<long, FileData>();
        Dictionary<string, FileData> alcheck2_ = new Dictionary<string, FileData>();

        public delegate bool ProgressedHandler(int id, string dir);
        public event ProgressedHandler Progressed;

        SffInfo info_;
        bool IsForwardDirectory(string dir)
        {
            return false;
        }
        void processfound(FileInfo fi)
        {
            if (Progressed(info_.Id, dir))
                return;

            // filter check
            if (!info_.match(fi.Name))
                return;

            if (fi.Length < info_.MinLength)
                return;

            FileData fd = new FileData(info_.CurIndex, fi.DirectoryName, fi.Name, fi.Length);
            
            if(alcheck1_.ContainsKey(fi.Length))
            {
                if (info_.IsDiffOrigin && alcheck1_[fi.Length].OrigIndex == fd.OrigIndex)
                    return;

                dups1.insert(THEMMV(ull, alcheck1[ull]));
                dups1.insert(THEMMV(ull, pFD));

                string ss1;
                DWORD dwError = alcheck1[ull]->GetCalculate1(ss1);
                if (dwError != NO_ERROR)
                {
                    APIERROR ae;
                    ae.pFile = pDir;
                    ae.dwLE = dwError;
                    if (!SendMessage(pD->hwnd_, WM_APP_APIERROR, (WPARAM)pD->thid_, (LPARAM) & ae))
                        return;
                }

                string ss2;
                dwError = pFD->GetCalculate1(ss2);
                if (dwError != NO_ERROR)
                {
                    APIERROR ae;
                    ae.pFile = pDir;
                    ae.dwLE = dwError;
                    if (!SendMessage(pD->hwnd_, WM_APP_APIERROR, (WPARAM)pD->thid_, (LPARAM) & ae))
                        return;
                }

                if (ss1 == ss2)
                {
                    if (!alcheck2[ss1])
                    {
                        if (!SendMessage(pD->hwnd_, WM_APP_ADDLINE2, (WPARAM)pD->thid_, (LPARAM)alcheck1[ull]))
                            return;

                        alcheck2[ss1] = pFD;
                    }

                    if (!SendMessage(pD->hwnd_, WM_APP_ADDLINE2, (WPARAM)pD->thid_, (LPARAM)pFD))
                        return;

                    alcheck2[ss2] = pFD;
                }
            }
            else
            {
                alcheck1[ull] = pFD; // .insert(map<ULL, CFileData*>::value_type(ull,pFD ));
            }
        }
        void doWork(SffInfo info, string next)
        {
            string dir = next != null ? next : info.CurDir;

            if (info.IsProcessedDir(dir))
                return;
            info.SetProcessedDir(dir);

            DirectoryInfo di = new DirectoryInfo(dir);
            foreach(DirectoryInfo subdir in di.GetDirectories())
            {
                process
            }


            WIN32_FIND_DATA wfd;
            HANDLE h = FindFirstFile(pDirFFF, &wfd);

            if (h != INVALID_HANDLE_VALUE)
            {
                processfound(pD, &wfd, pDir);
                while (FindNextFile(h, &wfd))
                {
                    processfound(pD, &wfd, pDir);
                }
            }
            else
            {
                DWORD le = GetLastError();
                APIERROR ae;
                ae.pFile = pDir;
                ae.dwLE = le;
                if (!SendMessage(pD->hwnd_, WM_APP_APIERROR, (WPARAM)pD->thid_, (LPARAM) & ae))
                    return;
            }

        }
    }
}
